CXX = g++
CXXFLAGS = -Wall -std=c++17
INCLUDES = -I. -Igrafos -Iuteis/insercoes -Iuteis/remocoes -Iuteis/buscas

SRC = main.cpp \
      grafos/grafos.cpp \
      uteis/insercoes/insercoes.cpp \
      uteis/remocoes/remocoes.cpp
      # adicione mais .cpp se tiver (ex: buscas.cpp)

OBJ = $(SRC:.cpp=.o)

TARGET = main

# Regra padrão
all: $(TARGET)

# Linkagem final
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

# Regra de compilação genérica
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Limpar apenas os objetos
clean:
	rm -f $(OBJ)

# Limpar tudo (objetos + binário final)
distclean: clean
	rm -f $(TARGET)
