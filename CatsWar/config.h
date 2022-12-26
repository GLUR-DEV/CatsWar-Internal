#pragma once

#include "include.h"

struct
{
	bool bAmmo = false;
	bool bAmmoInit = false;

	bool bHealth = false;
	bool bHealthInit = false;

	bool bFlower = false;
	bool bFlowerInit = false;
} cheats;

struct
{
	float ammoNum = 6969;
	float magNum = 6969;

	float healthNum = 6969;

	float flowerNum = 10;
} config;

struct
{
	float* ammoInit;
	float* magInit;

	float* healthInit;

	float* flowerInit;

	float ammoNum;
	float magNum;

	float healthNum;

	float flowerNum;
} init;