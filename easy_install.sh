#!/bin/bash

echo " _   _ _                  ____   _____"
echo "| \ | (_)                / __ \ / ____|"
echo "|  \| |_ _ __ ___   __ _| |  | | (___"
echo "| . ` | | '_ ` _ \ / _` | |  | |\___ \"
echo "| |\  | | | | | | | (_| | |__| |____) |"
echo "|_| \_|_|_| |_| |_|\__, |\____/|_____/"
echo "                    __/ |"
echo "                   |___/ helper script"
echo "Made by xerox123official and xshotD."
echo "License: MIT."

echo "##################################################################################"
echo "# This script was developed to easily build NimgOS without reading tons of docs  #"
echo "#  This script will request for root privilges to install dependencies for this  #"
echo "#                              at any time.                                      #"
echo "##################################################################################"

sleep 2

echo ""

echo "################## NOTICE #####################"
echo "# This script may only work on a Debian/Ubuntu #"
echo "#                 based system.                #"
echo "###############################################"

echo ""

sleep 3

echo "################################"
echo "# Installing a few packages... #"
echo "################################"

sleep 3
sudo apt install git xtightvncviewer nasm qemu gcc

echo ""

echo "##############################"
echo "# Cloning the git repository #"
echo "##############################"

echo ""

git clone https://github.com/Njifra/NimgOS.git
cd NimgOS
sleep 3

echo ""

echo "################################"
echo "# Making the 'build' directory #"
echo "################################"

mkdir build

echo ""

echo "#######################################"
echo "# Making the b4_linux file executable #"
echo "#######################################"

chmod +x b4_linux

echo ""

echo "#########################"
echo "# Done building NimgOS. #"
echo "#########################"

echo ""

echo "To run the OS, change directory using 'cd NimgOS'"
echo "             and execute ./b4_linux              "

echo ""

sleep 3

echo "Thanks for trying out NimgOS!"
