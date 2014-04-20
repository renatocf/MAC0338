BIN := test_sort
SRC := Sort.c test_sort.c
INC := SORT.h
OBJ := $(SRC:.c=.o)

CFLAGS  := -ansi -Wall -pedantic -O2 -g
LDFLAGS := 

CC := gcc

.PHONY: all
all: $(BIN)

$(BIN): $(OBJ) $(INC)
	$(CC) $^ -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) $(OBJ)

.PHONY: distclean
distclean: clean
	$(RM) $(BIN)
