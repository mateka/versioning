#pragma once

#include <iosfwd>
#include <cstdint>


namespace versioning {

    class version final {
    public:
        using type = std::uint8_t;

        explicit version(
            const type major,
            const type minor=0,
            const type patch=0
        ) noexcept;
        version(version&&) = default;
        version(const version&) = default;
        version& operator=(version&&) = default;
        version& operator=(const version&) = default;

        type major() const noexcept;
        type minor() const noexcept;
        type patch() const noexcept;

        void major(const type value) noexcept;
        void minor(const type value) noexcept;
        void patch(const type value) noexcept;
    private:
        type m_major;
        type m_minor;
        type m_patch;
    };

    std::ostream& operator<<(std::ostream& os, const version& v);

    bool operator==(const version& a, const version& b) noexcept;
    bool operator!=(const version& a, const version& b) noexcept;

    bool operator<(const version& a, const version& b) noexcept;
    bool operator>(const version& a, const version& b) noexcept;
    bool operator<=(const version& a, const version& b) noexcept;
    bool operator>=(const version& a, const version& b) noexcept;

}