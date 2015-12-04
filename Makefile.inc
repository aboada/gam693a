# Makefile config file

SHELL := /bin/bash

BASE = $(strip $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST)))))

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
