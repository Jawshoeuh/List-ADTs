#====================================
#   Joshua Stefan Pang (Jawshoeuh)
#   Created 8/1/2022 
#   This is the makefile for LinkedList1.
#   The code has been tested and run on a 
#   Raspberry Pi3 with Manjaro ARM Linux
#   (V 22.07)
#====================================

ADT_NAME = LinkedList
CFILES    = $(ADT_NAME).c ($ADT_NAME)Test.c
OFILES    = $(ADT_NAME).o ($ADT_NAME)Test.o
HFILES    = $(ADT_NAME).h
FLAGS     = -Wall
EXEFILE = $(ADT_NAME)Test

all: $(EXEFILE)

$(EXEFILE) : $(OFILES) $(HFILES)
	c99 -o  $(EXEFILE) $(OFILES)

$(OBJECTS) : $(CFILES) $(HFILES)
	c99 -c $(FLAGS) $(SOURCES)

clean      :
	rm -f $(EXEFILE) $(OFILES)

memcheck   : $(EXEFILE)
	valgrind --leak-check=full $(EXEFILE)

