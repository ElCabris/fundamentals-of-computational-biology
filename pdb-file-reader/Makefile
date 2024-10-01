# Variables del Compilador y Flags
CXX = g++
CXXFLAGS = -Wall -Iinclude -std=c++17
LDFLAGS = 

# Directorios
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include
LIB_DIR = lib
LIB_NAME = libatom.a

TEST_DIR = tests
TEST_BIN_DIR = bin

# Archivos Fuente
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Archivos de Prueba
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_BINS = $(TEST_SRCS:$(TEST_DIR)/%.cpp=$(TEST_BIN_DIR)/%)

# Target por Defecto
all: $(LIB_DIR)/$(LIB_NAME)

# Crear la Librería Estática
$(LIB_DIR)/$(LIB_NAME): $(OBJS) | $(LIB_DIR)
	@echo "Creando la librería estática $@..."
	ar rcs $@ $^

# Compilar Archivos Fuente a Objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@echo "Compilando $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Crear Directorios Necesarios
$(OBJ_DIR) $(LIB_DIR) $(TEST_BIN_DIR):
	mkdir -p $@

# Targets para Pruebas
tests: $(TEST_BINS)

$(TEST_BIN_DIR)/%: $(TEST_DIR)/%.cpp $(LIB_DIR)/$(LIB_NAME) | $(TEST_BIN_DIR)
	@echo "Compilando prueba $<..."
	$(CXX) $(CXXFLAGS) $< -L$(LIB_DIR) -latom -o $@

# Ejecutar Todas las Pruebas
run_tests: tests
	@echo "Ejecutando todas las pruebas..."
	@for test in $(TEST_BINS); do \
		echo "=== Ejecutando $$test ==="; \
		$$test; \
	done

# Limpiar Archivos Generados
clean:
	@echo "Limpiando archivos generados..."
	rm -rf $(OBJ_DIR) $(LIB_DIR) $(TEST_BIN_DIR) compile_commands.json

# Generar compile_commands.json usando bear
compile_commands.json:
	bear -- make all

# Phony Targets
.PHONY: all clean tests run_tests compile_commands.json

