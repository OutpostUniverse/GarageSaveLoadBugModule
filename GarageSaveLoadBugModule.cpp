// This module helps with reproducing the Garage Save/Load bug
// The bug presents as a crash when trying to view the storage bays of a garage
// The cause is corruption of contained unit records
// Corruption happens when the unit array is aligned appropriately and the game is saved twice
// This module helps to align the unit array address so the problem presents itself reliably
// This can be used in conjunction with the GarageSaveLoadBugLevel to reproduce

// Use this module by starting Outpost2.exe with the /loadmod parameter:
// Outpost2.exe /loadmod GarageSaveLoadBugModule

// Compile on Linux with:
// make


#define EXPORT extern "C" __declspec(dllexport)


EXPORT void mod_init()
{
}

EXPORT void mod_destroy()
{
}
