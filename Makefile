CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = bins/app
SRCS = src/main.cpp src/Game.cpp src/Trie.cpp src/GamesDatabase.cpp

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -I src -o $(TARGET)

clean:
	rm -f $(TARGET)

run:
	./$(TARGET) $(k) "$(prefix)"