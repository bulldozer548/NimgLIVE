#ifndef NIMGOS_STDARG_H
#define NIMGOS_STDARG_H

#ifndef VA_LIST
#define VA_LIST
typedef void* va_list;
#endif

#define va_start(ap, p) (ap = (char*) (&(p)+1))
#define va_arg(ap, type) ((type*) (ap += sizeof(type)))[-1]
#define va_end(ap)

#endif //NIMGOS_STDARG_H
