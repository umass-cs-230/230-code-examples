CC = gcc
FLAGS = -g
SRCS = $(wildcard *.c)
ASMS = $(patsubst %.c,%.s,$(SRCS))
OBJS = $(patsubst %.c,%.o,$(SRCS))
BINS = $(patsubst %.c,%,$(SRCS))

all: $(BINS)

%: %.c
	$(CC) $(FLAGS) -o $@ $<

clean:
	rm -f $(BINS)
	rm -f *~
