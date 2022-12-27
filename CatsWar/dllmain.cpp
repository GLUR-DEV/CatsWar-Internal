#include "include.h"

uintptr_t GetPointerAddress(uintptr_t ptr, std::vector<uintptr_t> offsets)
{
    uintptr_t addr = ptr;
    for (int i = 0; i < offsets.size(); i++)
    {
        addr = *(uintptr_t*)addr;
        addr += offsets[i];
    }
    return addr;
}

void MainThread()
{
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);
    std::cout << "Cheat Injected\n\n";

    Sleep(2000);
    FreeConsole();

    AllocConsole();
    freopen_s(&f, "CONOUT$", "w", stdout);

    std::cout << "Cheat made by GLUR. GLUR#4861 on discord\n";
    std::cout << "If you downloaded this program from anywhere other than GLUR-DEV github(https://github.com/GLUR-DEV) then your computer may be at risk. If this is the case delete all traces of this program now!\n\n";

    std::cout << "Keybinds:\n";
    std::cout << "[ctr + 1] For Unlimited Ammo\n";
    std::cout << "[ctr + 2] For Unlimited Health\n";
    std::cout << "[ctr + 3] For Instant Win(You have to pick up a flower for it to register)\n";
    std::cout << "[ctr + 4] For Airjump\n\n";

    std::cout << "Log:\n";

    cheatThread();
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)MainThread, NULL, NULL, NULL);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
