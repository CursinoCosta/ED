CC := g++
SHELL := /bin/bash
SRCDIR := src
OBJDIR := obj
BINDIR := bin


SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(OBJDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

CFLAGS :=  -g -Wall -std=c++17 
INC := -I include/ 

$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $< 

main: $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(INC) $^ -o $(BINDIR)/tp2.out 

tests: $(EXE)
	for file in testes/*.txt; do time ./bin/pa11.out < $$file; done


all: main

clean:
	$(RM) -r $(OBJDIR)/* $(BINDIR)/* coverage/* *.gcda *.gcno gmon.out

.PHONY: clean
  