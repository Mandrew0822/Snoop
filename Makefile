CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++17 -O3
BIN = snoop
INSTALL_PATH = /usr/local/bin

$(BIN): snoop.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

install: $(BIN)
	cp $(BIN) $(INSTALL_PATH)

clean:
	rm -f $(BIN)
