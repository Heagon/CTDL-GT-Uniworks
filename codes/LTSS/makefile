CXX = g++
CXXFLAGS = -I "C:\Program Files (x86)\Microsoft SDKs\MPI\Include" -fopenmp
LDFLAGS = -L "C:\Program Files (x86)\Microsoft SDKs\MPI\Lib\x64" -lmsmpi
TARGET = Parallel

all: $(TARGET)

$(TARGET): Parallel.cpp
	$(CXX) $(CXXFLAGS) Parallel.cpp -o $(TARGET) $(LDFLAGS)

clean:
	del $(TARGET).exe