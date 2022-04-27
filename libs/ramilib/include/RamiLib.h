#pragma once

#include "raylib.h"
#include <string>

/// <summary>
/// Inicaliza el Audio Device (Se tiene que hacer desde el principio)
/// </summary>
void initMusicDevice();

/// <summary>
/// Inicializa una nueva pieza de Musica
/// </summary>
/// <param name="musicName"> Nombre del archivo de musica </param>
/// <param name="musicOn"> Define si se inicia y se pone en play o solo se inicializa </param>
/// <returns> Retorna la pieza de sonido inicializado </returns>
Music InitNewMusic(const char* musicName, bool musicOn);

/// <summary>
/// Updatea la musica frame por frame (Utilizar en Update)
/// </summary>
/// <param name="music"> Recibe la pieza de musica a Loopear </param>
void updateMusicStream(Music music);

/// <summary>
/// Inicializa un nuevo Sonido
/// </summary>
/// <param name="soundName"> Nombre del archivo de Sonido </param>
/// <returns> Retorna el sonido inicializado </returns>
Sound InitNewSound(const char* soundName);

/// <summary>
/// Desinializa una pieza de musica
/// </summary>
///<param name="music"> Recibe la pieza de musica a desinicializar </param>
///<returns> </returns>
void Disincialize(Music music);

/// <summary>
/// Desinializa un sonido
/// </summary>
/// <param name="sound"> Recibe un sonido a desinicializar </param>
void Disincialize(Sound sound);

/// <summary>
/// Desinicializa el audioDevice (Hacer al final)
/// </summary>
void finishMusic();
