# Makefile config file

SHELL := /bin/bash

BASE = /home/mando/development/C++/Math693A_Project/gam693a

CC = g++

CCFLAGS = -Wall

ARCH      = ar
ARCHFLAGS = cr

RANLIB = ranlib

SRC       = $(BASE)/src
INCLUDE   = $(BASE)/include
LIB       = $(BASE)/lib
GAM_LIB   = $(LIB)/libgam.a
TESTS     = $(BASE)/tests

CCFLAGS += -std=c++11 -fPIC -I$(INCLUDE) -c
