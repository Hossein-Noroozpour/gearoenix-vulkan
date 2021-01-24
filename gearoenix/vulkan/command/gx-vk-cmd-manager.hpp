#ifndef GEAROENIX_VULKAN_COMMAND_MANAGER_HPP
#define GEAROENIX_VULKAN_COMMAND_MANAGER_HPP
#include "../../render/gx-rnd-build-configuration.hpp"
#ifdef GX_RENDER_VULKAN_ENABLED
#include "../../core/macro/gx-cr-mcr-getter-setter.hpp"
#include "../../platform/macro/gx-plt-mcr-lock.hpp"
#include "gx-vk-cmd-buffer.hpp"
#include "gx-vk-cmd-pool.hpp"
#include "gx-vk-cmd-type.hpp"
#include <map>
#include <optional>
#include <thread>

namespace gearoenix::vulkan::command {
struct Manager final {
    GX_GET_CRRF_PRV(device::Logical, logical_device)

private:
    GX_CREATE_GUARD(this)
    std::map<std::size_t, Pool> indexed_pools;
    std::map<std::thread::id, Pool> threads_pools;

public:
    Manager(const Manager&) = delete;
    Manager(Manager&&) = delete;
    explicit Manager(const device::Logical& logical_device) noexcept;
    ~Manager() noexcept;
    Manager& operator=(const Manager&) = delete;
    Manager& operator=(Manager&&) = delete;
    [[nodiscard]] Buffer create(Type buffer_type, std::optional<std::size_t> thread_index = std::nullopt) noexcept;
};
}
#endif
#endif
