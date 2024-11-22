# Nombre del ejecutable
TARGET = filter 

# Directorios
SRC_DIR = src
INCLUDE_DIR = include
LIB_DIR = libs

# Archivos fuente y objeto
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(SRC_DIR)/%.o)

# archivo de resultados
RESULTS = results.txt

#script
SCRIPT = search_atoms.sh

# Compilador y opciones
CXX = g++
CXXFLAGS = -I$(INCLUDE_DIR) -L$(LIB_DIR) -latom -Wall -Wextra -std=c++17

# Reglas
all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CXX) -o $@ $^ $(CXXFLAGS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

run_script: $(RESULTS)
	@echo "Ejeuntado el script..."
	@bash $(SCRIPT)

$(RESULTS):
	@touch $(RESULTS)

clean:
	rm -f $(SRC_DIR)/*.o $(TARGET)
	@rm -f $(RESULTS)

.PHONY: all clean

