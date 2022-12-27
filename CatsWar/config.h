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

	bool bAirjump = false;
	bool bAirjumpInit = false;
} cheats;

struct
{
	float ammoNum = 6969;
	float magNum = 6969;

	float healthNum = 6969;

	float flowerNum = 10;

	float jumpMaxNum = 6969;
	float jumpNum = 0;
} config;

struct
{
	float* ammoInit;
	float* magInit;

	float* healthInit;

	float* flowerInit;

	float* jumpMaxInit;
	float* jumpInit;

	float ammoNum;
	float magNum;

	float healthNum;

	float flowerNum;

	float jumpMaxNum;
	float jumpNum;
} init;
