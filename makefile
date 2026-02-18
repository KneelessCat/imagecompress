SOURCE = $(wildcard src/*.c)
OBJECTS = $(patsubst src/%.c, build/%.o, $(SOURCE))

FLAGS = -Wall -Wextra -g -O

BUILD = build/
BIN = bin/
TARGET = bin/pcomp

$(BUILD) :
	mkdir -p $(BUILD)

$(BIN) :
	mkdir -p $(BIN)


build/%.o : src/%.c
	gcc -c $(FLAGS) $< -o $@

$(TARGET): $(OBJECTS)
	gcc $(FLAGS) $(OBJECTS) -o $(TARGET)



all : $(TARGET)


clean:
	rm -rf build/*.o $(TARGET)
