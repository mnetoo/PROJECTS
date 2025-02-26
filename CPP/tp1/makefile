# Flags de compilação para C++
CXXFLAGS = -Wall -Wextra -g -std=c++11  # Usando C++11 ou outra versão que preferir
CXX = g++  # Usando o compilador C++

# Gera o executável
all: tp1

# Compila o arquivo racional.cpp
racional.o: racional.cpp racional.hpp
	$(CXX) -c $(CXXFLAGS) racional.cpp

# Compila o arquivo tp1.cpp
tp1.o: tp1.cpp racional.hpp
	$(CXX) -c $(CXXFLAGS) tp1.cpp

# Gera o executável final
tp1: tp1.o racional.o
	$(CXX) -o tp1 tp1.o racional.o

# Limpeza dos arquivos gerados
clean:
	rm -f *.o *~ tp1