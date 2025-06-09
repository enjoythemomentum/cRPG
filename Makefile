# Kompilator C++
CXX = g++

# Flagi kompilatora
CXXFLAGS = -std=c++11 -Wall -g

# Nazwa pliku wykonywalnego
TARGET = rpg

# --- ZMIANY SĄ TUTAJ ---

# Zmienna do przekazania z linii poleceń, np. make EXCLUDE=plik.cpp
EXCLUDE ?=

# Automatycznie znajdź wszystkie pliki źródłowe .cpp
ALL_SOURCES = $(wildcard *.cpp)

# Odfiltruj pliki z listy, które zostały podane w zmiennej EXCLUDE
SOURCES = $(filter-out $(EXCLUDE), $(ALL_SOURCES))

# --- KONIEC ZMIAN ---

# Zamień rozszerzenia .cpp na .o dla plików obiektowych
OBJECTS = $(SOURCES:.cpp=.o)

# Domyślna reguła: buduje wszystko
all: $(TARGET)

# Reguła linkowania
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Reguła kompilacji
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Reguła czyszczenia
clean:
	rm -f $(TARGET) $(OBJECTS)

# Reguła do debugowania - pokazuje, które pliki zostaną skompilowane
print-sources:
	@echo "Kompilowane pliki: $(SOURCES)"

.PHONY: all clean print-sources
