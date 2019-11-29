# GarageSaveLoadBugModule

This is a module for Outpost 2 that helps with reproducing the Garage Save/Load bug.

The garage save/load bug presents as a crash when trying to view the storage bays of a garage. The cause is corruption of the contained unit records. Corruption happens when the unit array is aligned appropriately and the game is saved twice. The problem alignment happens about 1/15 of the time.

This module helps to align the unit array address so the problem presents itself reliably. This can be used in conjunction with the [GarageSaveLoadBugLevel](https://github.com/OutpostUniverse/GarageSaveLoadBugLevel) project to reproduce the bug.

The purpose of this module is to aid in producing a patch for the bug, as well as verifying the patch works correctly.

# Compiling

## Linux

From the project root folder run:
```
make
```

# Running

## Linux

To run Outpost 2 with this module, from the project root folder run:
```
make run
```

Run support requires the `$Outpost2Path` environment variable to be set. The `make run` command first compiles the code if it is out of date, installs the code to the Outpost 2 folder, then runs Outpost 2 with a command line option to load the module. Installation can be done independently of running by using the `make install` command instead.

If you wish to avoid setting an environment variable, you can specify the path directly in the `make` command:
```
make run Outpost2Path=/Path/To/Outpost2/Folder/
```

## Manually

This assumes the code has already been compiled and copied to a `GarageSaveLoadBugModule` subfolder of the Outpost 2 folder, and named as `op2mod.dll`.

To manually load Outpost 2 with the module, from the Outpost 2 folder, run:
```
Outpost2.exe /loadmod GarageSaveLoadBugModule
```

# Reproducing the Bug

To reproduce the bug, load a level with a garage that contains units, such as GarageSaveLoadBugLevel, and save twice. Select the garage, and view the storage bays. At this point the game should crash.

# Additional Links

The [op2ext](https://github.com/OutpostUniverse/op2ext) project contains an [Issue for the GarageSaveLoadBug](https://github.com/OutpostUniverse/op2ext/issues/204).
