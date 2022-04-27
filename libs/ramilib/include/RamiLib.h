#pragma once

#include "raylib.h"
#include <string>

void initMusicDevice();

void InitNewMusic(const char* musicName, bool musicOn);

void updateMusicStream(Music music);

Sound InitNewSound(const char* soundName);

void Disincialize(Music music);
void Disincialize(Sound sound);

/// <summary>
/// 
/// </summary>
///<returns> </returns>
void finishMusic();