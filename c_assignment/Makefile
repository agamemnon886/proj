
TARGET = parse_rpc
CC = gcc
RM = rm -f
CFLAGS = -c -Wall -I.
OBJS = $(patsubst %.c, %.o, $(wildcard *.c))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

%.o: %.c %.h
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) $(TARGET) $(OBJS)

