#include <cstddef>
#include <cstdint>
#include "OP2Memory.h"
#include "Log.h"
#include "Log/LoggerMessageBox.h"


void* AlignedAlloc(std::size_t allocSize);


LoggerMessageBox logger;


#define EXPORT extern "C" __declspec(dllexport)


EXPORT void mod_init() {
	SetLoggerDebug(&logger);
	SetLoggerMessage(&logger);
	SetLoggerError(&logger);

	if (!EnableOp2MemoryPatching()) {
		LogError("GarageSaveLoadBugModule: Failed to enable memory patching");
	}
	if (!Op2RelinkCall(0x00435665, reinterpret_cast<const void*>(&AlignedAlloc))) {
		LogError("GarageSaveLoadBugModule: Failed to patch unit array memory allocator");
	}
}


__cdecl void* AlignedAlloc(std::size_t allocSize) {
	constexpr std::uintptr_t OriginalAllocAddress = 0x004C21F0;
	auto allocFunction = reinterpret_cast<decltype(&AlignedAlloc)>(OriginalAllocAddress);

	auto result = reinterpret_cast<std::uintptr_t>(allocFunction(allocSize + 120));
	if (result != 0) {
		result += (120 - (result % 120));
	}
	return reinterpret_cast<void*>(result);
}
