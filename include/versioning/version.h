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
        );
        version(version&&) = default;
        version(const version&) = default;
        version& operator=(version&&) = default;
        version& operator=(const version&) = default;

        type major() const;
        type minor() const;
        type patch() const;

        void major(const type value);
        void minor(const type value);
        void patch(const type value);
    private:
        type m_major;
        type m_minor;
        type m_patch;
    };

    std::ostream& operator<<(std::ostream& os, const version& v);

    bool operator==(const version& a, const version& b);
    bool operator!=(const version& a, const version& b);

    bool operator<(const version& a, const version& b);
    bool operator>(const version& a, const version& b);
    bool operator<=(const version& a, const version& b);
    bool operator>=(const version& a, const version& b);

}