BUILD := Build

CXX := clang++
CXXFLAGS := -std=c++23 -Wall -Wextra -I../Include -IInclude -ITest

SRCS := $(wildcard *.cpp) \
        $(wildcard Math/*.cpp) \
	$(wildcard Robot/*.cpp)

OBJS := $(patsubst %.cpp,$(BUILD)/%.o,$(SRCS))

TARGET := $(BUILD)/Main

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $^ -o $@

$(BUILD)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD)