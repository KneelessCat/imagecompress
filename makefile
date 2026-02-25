SOURCE = $(wildcard src/*.c)
OBJECTS = $(patsubst src/%.c, build/%.o, $(SOURCE))

FLAGS = -Wall -Wextra -g -O

ifeq ($(OS),Windows_NT)
     BUILD = build
     BIN = bin
     MKDIR = mkdir
     RM = del /Q
     RMDIR = rmdir /S /Q
     TARGET = $(BIN)\pcomp.exe
	 
else
    BUILD = build/
    BIN = bin/
    MKDIR = mkdir -p
    RM = rm -f
    RMDIR = rm -rf
    TARGET = $(BIN)/pcomp
endif


DEPS = $(OBJECTS:.o=.d)
-include $(DEPS)


$(OBJECTS) : | $(BIN) $(BUILD)

$(BUILD) :
	$(MKDIR) $(BUILD)

$(BIN) :
	$(MKDIR) $(BIN)


build/%.o : src/%.c
	gcc -MMD -MP -MF $(@:.o=.d) -c $(FLAGS) $< -o $@


$(TARGET): $(OBJECTS)
	$(RM) $(TARGET)
	gcc $(FLAGS) $(OBJECTS) -o $(TARGET)



all : $(TARGET) 


clean:
	$(RMDIR) $(BUILD) 
	$(RM) $(TARGET)
	
	
.SUFFIXES:

.PHONY : all clean
