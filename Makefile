CC=gcc
CPPFLAGS=-MMD
CFLAGS=-Wall -Wextra -Wvla -std=c99 -pedantic
LDFLAGS=

SRC=src/token.c src/lexer.c src/bfc.c src/token_da.c src/executor.c
OBJ=${SRC:.c=.o}
DEP=${OBJ:.o=.d}

BIN=bfc

.PHONY: all $(BIN) clean debug release

all: debug

$(BIN): $(OBJ) $(HDR)
	$(CC) $(LDFLAGS) -o $@ $^

debug: CFLAGS+=-O0 -ggdb -fsanitize=address
debug: LDFLAGS+=-fsanitize=address
debug: $(BIN)


release: CPPFLAGS+=-DNDEBUG
release: CFLAGS+=-O3
release: $(BIN)

-include $(DEP)


clean:
	$(RM) $(OBJ) $(BIN) $(DEP)
