#ifndef GEAROENIX_PLATFORM_MAIN_ENTRY_HPP
#define GEAROENIX_PLATFORM_MAIN_ENTRY_HPP
#include "gx-plt-build-configuration.hpp"

#ifdef GX_PLT_WINAPI
#include "winapi/gx-plt-win-main-entry.hpp"
#else
#error "Unimplemented or unexpected platform interface."
#endif

#endif