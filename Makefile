CC = gcc
CFLAGS = -g -Wall -Wextra -Wunreachable-code -Wconversion -Wshadow -std=c99

BUILD_DIR = build
BINARY = stack-vm
SOURCE = $(wildcard src/*.c)
OBJ = $(SOURCE:src/%.c=$(BUILD_DIR)/%.o)
DEP = $(OBJ:%.o=%.d)

.PHONY all
all : $(BINARY)

$(BINARY) : $(BUILD_DIR)/$(BINARY)
	cp -f -T $< $@

$(BUILD_DIR)/$(BINARY) : $(OBJ)
	mkdir -p $(@D)
	# link all object files to a single executable
	$(CC) $(CFLAGS) $^ -o $@

# include all .d files, skip if they do not exist yet
-include $(DEP)

# potential header dependency is covered by `-include $(DEP)`
$(BUILD_DIR)/%.o : src/%.c
	mkdir -p $(@D)
# -MMD flag creates .d file
	$(CC) $(CFLAGS) -I ./src/include -MMD -c $< -o $@

.PHONY : clean
clean :
	-rm -f $(BUILD_DIR)/$(BINARY) $(OBJ) $(DEP)
