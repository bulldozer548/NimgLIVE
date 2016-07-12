#include "stdio.h"
#include "../display/display.h"

char digit_str_l[]    = "0123456789abcdef";
char digit_str_u[]    = "0123456789ABCDEF";

char printf_buffer[PRINTF_BUFFER_SIZE];

#define DEFINE_NUM2STR(base, num_type, max_strlen_pc, str_case)             \
void num_type ## 2str_ ## base ## str_case (char *dest, num_type num) {   \
                                                                            \
    int i;                                                                  \
    bool print_flag;                                                        \
    int digits[max_strlen_pc * sizeof(num_type)];                           \
                                                                            \
   if (num < 0) {                                                          \
        *dest   = '-';                                                      \
        dest++;                                                             \
        num = -num;                                                         \
    }                                                                   \
                                                                            \
    for( i=0 ; i < sizeof(num_type) * max_strlen_pc ; i++) {                 \
        digits[i]   = num % base;                                           \
        num         /= base;                                                \
    }                                                                       \
    for( i--, print_flag=0 ; i>=0 ; i-- ) {                                  \
        if (digits[i]) {                                                      \
            print_flag  = 1;                                                \
        }                                                                   \
        if (print_flag) {                                                     \
            *dest   = digit_str_## str_case [digits[i]];                    \
            dest++;                                                         \
        }                                                                   \
    }                                                                       \
                                                                            \
    if (!print_flag) {                                                        \
        *dest   = '0';                                                      \
        dest++;                                                             \
    }                                                                       \
                                                                            \
    *dest   = 0;                                                            \
}



DEFINE_NUM2STR(10, char, 3, l)
DEFINE_NUM2STR(10, int,  3, l)
DEFINE_NUM2STR(10, long, 20, l)
DEFINE_NUM2STR(16, char, 2, l)
DEFINE_NUM2STR(16, char, 2, u)
DEFINE_NUM2STR(16, int,  2, l)
DEFINE_NUM2STR(16, int,  2, u)
DEFINE_NUM2STR(16, long, 20, l)
DEFINE_NUM2STR(16, long, 20, u)


void long2str_10h(char *dest, unsigned long num, unsigned char precision) {
    char need_plus  = 0;

    if (precision && num >= 1073741824) { 
        int2str_10l(dest, num / 1073741824);
        num %= 1073741824;

        while (*dest != 0) dest++;
		
        *(dest++) = 'G';

        precision--;
        need_plus = 1;
    }

    if (precision && num >= 1048576) { 

        if (need_plus)
			*(dest++) = '+';

        int2str_10l(dest, num / 1048576);
        num %= 1048576;

        while (*dest != 0) dest++;
		
        *(dest++) = 'M';

        precision--;
        need_plus = 1;
    }
    
    if (precision && num >= 1024) {
        if (need_plus)
			*(dest++) = '+';

        int2str_10l(dest, num / 1024);
        num %= 1024;

        while (*dest != 0) dest++;
		
        *dest = 'k';
        *(++dest) = 0;

        precision--;
        need_plus = 1;
    }

    if (precision && num >= 0) {
        /* 1kB */
        if (need_plus)
			*(dest++)   = '+';

        int2str_10l(dest, num);
        need_plus = 1;
    }

    if (!need_plus) {
        *(dest++) = '0';
        *dest = 0;
    }
}

#define SPRINT_C(c)             \
    tmp_char = (c);		        \
    if (buffer == NULL) {       \
        write_char(tmp_char);   \
    }                           \
    else if (retval < size) {   \
        *(buffer++) = tmp_char; \
    }                           \
    retval++;

#define SPRINT_S(str)               \
    tmp_ptr_m = (str);              \
    while (*tmp_ptr_m) {            \
        SPRINT_C(*(tmp_ptr_m++));   \
    }

#define SPRINT_N(type, base, str_case)                              \
    tmp_ ## type = va_arg(ap, type);                                \
    type ## 2str_ ## base ## str_case (tmp_str, tmp_ ## type);      \
    SPRINT_S(tmp_str);                                              \

static int _output_helper(char *buffer, size_t size, const char *format, va_list ap) {

    int retval          = 0;
    int tmp_int         = 0;
    char tmp_str[25]    = "";
    char *tmp_ptr_m     = NULL;
    char tmp_char       = 0;
    char *tmp_ptr       = 0;
    
    while (*format) {

        if (*format != '%') {
            SPRINT_C(*(format++));
            continue;
        }

        if (*(++format) == '%') {
            SPRINT_C('%');
            continue;
        }

        switch(*(format++)) {
            case 'i':
            case 'd': SPRINT_N(int, 10, l); break;

            case 'x': SPRINT_N(int, 16, l); break;

            case 'X': SPRINT_N(int, 16, u); break;

            case 'H': 
                // TODO: use var size formats here
                //
                long2str_10h(tmp_str, va_arg(ap, int), 10);
                SPRINT_S(tmp_str);
                break;

            case 's':
                tmp_ptr = va_arg(ap, char *);
                SPRINT_S(tmp_ptr);
                break;

        }

    }

    return retval;
}

int vsnoutput(char *buffer, size_t size, const char *format, va_list ap) {
    if (buffer == NULL)
        write_string("ERROR! Tried to print to NULL buffer.");
	
    return _output_helper(buffer, size, format, ap);
}

int snoutput(char *buffer, size_t size, const char *format, ...) {
  va_list ap;
  int retval;
  
  va_start(ap, format);
  retval = vsnoutput(buffer, size, format, ap);
  va_end(ap);

  return (retval);
}

int voutput(const char *format, va_list ap) {
    return _output_helper(NULL, 0, format, ap);
}

int output(const char *format, ...) {
    va_list ap;
    int retval;
    va_start(ap, format);
    retval  = voutput(format, ap);
    va_end(ap);

    return (retval);
}
