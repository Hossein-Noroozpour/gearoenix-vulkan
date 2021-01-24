#ifndef GEAROENIX_VULKAN_SWAPCHAIN_HPP
#define GEAROENIX_VULKAN_SWAPCHAIN_HPP
#include "../render/gx-rnd-build-configuration.hpp"
#ifdef GX_RENDER_VULKAN_ENABLED
#include "../core/macro/gx-cr-mcr-getter-setter.hpp"
#include "gx-vk-loader.hpp"
#include "image/gx-vk-img-view.hpp"
#include <vector>

namespace gearoenix::vulkan::device {
struct Logical;
}

namespace gearoenix::vulkan::sync {
struct Semaphore;
}

namespace gearoenix::vulkan {
struct Swapchain final {
    GX_GET_CRRF_PRV(device::Logical, logical_device)
    GX_GET_CREF_PRV(VkSurfaceFormatKHR, format)
    GX_GET_VAL_PRV(VkSwapchainKHR, vulkan_data, nullptr)
    GX_GET_CREF_PRV(std::vector<image::View>, image_views)

public:
    explicit Swapchain(const device::Logical& d) noexcept;
    ~Swapchain() noexcept;
    [[nodiscard]] std::uint32_t get_next_image_index(const sync::Semaphore& semaphore) noexcept;
    void initialize() noexcept;
};
}
#endif
#endif
