SRCS = wgrep.c
TARG = wgrep

CC = gcc
OPTS = -Wall -Werror

OBJS = $(SRCS:.c=.o)

all: $(TARG)

$(TARG): $(OBJS)
	$(CC) -o $(TARG) $(OBJS)

%.o: %.c
	$(CC) $(OPTS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(TARG)