#include "include.h"

int delay = 300;

uintptr_t moduleAddress;
uintptr_t playerOffset = 0x48F6CC8;

void initThread()
{
	init.ammoInit = (float*)GetPointerAddress(moduleAddress + playerOffset, { 0x0,0x20,0x59C });
	init.magInit = (float*)GetPointerAddress(moduleAddress + playerOffset, { 0x0,0x20,0x534 });

	init.ammoNum = *init.ammoInit, init.magNum = *init.magInit;

	init.healthInit = (float*)GetPointerAddress(moduleAddress + playerOffset, { 0x0,0x20,0x550 });

	init.healthNum = *init.healthInit;

	init.flowerInit = (float*)GetPointerAddress(moduleAddress + playerOffset, { 0x0,0x20,0x530 });

	init.flowerNum = *init.flowerInit;

	init.jumpMaxInit = (int*)GetPointerAddress(moduleAddress + playerOffset, { 0x0,0x20,0x2C0 });
	init.jumpInit = (int*)GetPointerAddress(moduleAddress + playerOffset, { 0x0,0x20,0x348 });

	init.jumpMaxNum = *init.jumpMaxInit, init.jumpNum = *init.jumpInit;
}

void cheatThread()
{
	moduleAddress = (uintptr_t)GetModuleHandle("CatsWar-Win64-Shipping.exe");
	std::thread init(initThread);

	std::thread thread1(ammoThread);
	std::thread thread2(healthThread);
	std::thread thread3(flowerThread);
	std::thread thread4(airjumpThread);

	while (true)
	{
		if (GetAsyncKeyState(VK_CONTROL) & GetAsyncKeyState(0x31))
		{
			if (cheats.bAmmo == false)
			{
				std::cout << "[ctr + 1] Pressed. Unlimited Ammo on.\n";
				initThread();

				cheats.bAmmoInit = false;
			}
			else
			{
				std::cout << "[ctr + 1] Pressed. Unlimited Ammo off.\n";
			}

			cheats.bAmmo = !cheats.bAmmo;
			Sleep(delay);
		}

		if (GetAsyncKeyState(VK_CONTROL) & GetAsyncKeyState(0x32))
		{
			if (cheats.bHealth == false)
			{
				std::cout << "[ctr + 2] Pressed. Unlimited Health on.\n";
				initThread();

				cheats.bHealthInit = false;
			}
			else
			{
				std::cout << "[ctr + 2] Pressed. Unlimited Health off.\n";
			}

			cheats.bHealth = !cheats.bHealth;
			Sleep(delay);
		}

		if (GetAsyncKeyState(VK_CONTROL) & GetAsyncKeyState(0x33))
		{
			if (cheats.bFlower == false)
			{
				std::cout << "[ctr + 3] Pressed. Instant Win on.\n";
				initThread();
				
				cheats.bFlowerInit = false;
			}
			else
			{
				std::cout << "[ctr + 3] Pressed. Instant Win off.\n";
			}

			cheats.bFlower = !cheats.bFlower;
			Sleep(delay);
		}

		if (GetAsyncKeyState(VK_CONTROL) & GetAsyncKeyState(0x34))
		{
			if (cheats.bAirjump == false)
			{
				std::cout << "[ctr + 4] Pressed. Airjump on.\n";
				initThread();

				cheats.bAirjumpInit = false;
			}
			else
			{
				std::cout << "[ctr + 4] Pressed. Airjump off.\n";
			}

			cheats.bAirjump = !cheats.bAirjump;
			Sleep(delay);
		}

		Sleep(1);
	}
}

void ammoThread()
{
	while (true)
	{
		if (cheats.bAmmo == true)
		{
			float* ammo = (float*)GetPointerAddress(moduleAddress + playerOffset, { 0x0,0x20,0x59C });
			float* mag = (float*)GetPointerAddress(moduleAddress + playerOffset, { 0x0,0x20 ,0x534 });
			*ammo = config.ammoNum, *mag = config.magNum;
		}
		else
		{
			if (cheats.bAmmoInit == false)
			{
				*init.ammoInit = init.ammoNum, *init.magInit = init.magNum;

				cheats.bAmmoInit = true;
			}
		}

		Sleep(1);
	}
}

void healthThread()
{
	while (true)
	{
		if (cheats.bHealth == true)
		{
			float* health = (float*)GetPointerAddress(moduleAddress + playerOffset, { 0x0,0x20,0x550 });
			*health = config.healthNum;
		}
		else
		{
			if (cheats.bHealthInit == false)
			{
				*init.healthInit = init.healthNum;

				cheats.bHealthInit = true;
			}
		}

		Sleep(1);
	}
}

void flowerThread()
{
	while (true)
	{
		if (cheats.bFlower == true)
		{
			float* flower = (float*)GetPointerAddress(moduleAddress + playerOffset, { 0x0,0x20,0x530 });
			*flower = config.flowerNum;
		}
		else
		{
			if (cheats.bFlowerInit == false)
			{
				*init.flowerInit = init.flowerNum;
				
				cheats.bFlowerInit = true;
			}
		}

		Sleep(1);
	}
}

void airjumpThread()
{
	while (true)
	{
		if (cheats.bAirjump == true)
		{
			int* jumpmax = (int*)GetPointerAddress(moduleAddress + playerOffset, { 0x0,0x20,0x2C0 });
			int* jump = (int*)GetPointerAddress(moduleAddress + playerOffset, { 0x0,0x20,0x348 });
			*jumpmax = config.jumpMaxNum;
			*jump = config.jumpNum;
		}
		else
		{
			if (cheats.bAirjumpInit == false)
			{
				*init.jumpMaxInit = init.jumpMaxNum, *init.jumpInit = init.jumpNum;

				cheats.bAirjumpInit = true;
			}
		}

		Sleep(1);
	}
}
