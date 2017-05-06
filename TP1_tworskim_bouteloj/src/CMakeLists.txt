cmake_minimum_required(VERSION 3.0)

project(modprog)

set(SRCS
    Height.cpp
    WaveModel.cpp
    GerstnerWave.cpp
    GerstnerWaveModel.cpp
    Dvector.cpp
    )
    
set(HEADERS
    Height.h
    WaveModel.h
    GerstnerWave.h
    GerstnerWaveModel.h
    Dvector.h
    )


add_executable(modprog ${SRCS} ${HEADERS})
