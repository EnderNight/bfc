CC=gcc
CPPFLAGS=
CFLAGS=-Wall -Wextra -Wvla -std=c99 -pedantic
LDFLAGS=

SRC=src/bfc.c
OBJ=${SRC:.c=.o}

BIN=bfc

.PHONY: all $(BIN) clean debug release

all: debug

$(BIN): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

debug: CFLAGS+=-O0 -ggdb -fsanitize=address
debug: LDFLAGS+=-fsanitize=address
debug: $(BIN)


release: CPPFLAGS+=-DNDEBUG
release: CFLAGS+=-O3
release: $(BIN)


clean:
	$(RM) $(OBJ) $(BIN)
