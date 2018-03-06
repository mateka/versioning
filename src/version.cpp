#include <versioning/version.h>
#include <iostream>
#include <tuple>


namespace versioning {

    version::version(const type major, const type minor, const type patch)
        : m_major{major}, m_minor{minor}, m_patch{patch}
    {}

    version::type version::major() const { return m_major; }
    version::type version::minor() const { return m_minor; }
    version::type version::patch() const { return m_patch; }

    void version::major(const version::type value) { m_major = value; }
    void version::minor(const version::type value) { m_minor = value; }
    void version::patch(const version::type value) { m_patch = value; }

    std::ostream& operator<<(std::ostream& os, const version& v) {
        return os
            << static_cast<int>(v.major()) << "."
            << static_cast<int>(v.minor()) << "."
            << static_cast<int>(v.patch());
    }

    bool operator==(const version& a, const version& b) {
        return std::make_tuple(a.major(), a.minor(), a.patch()) == std::make_tuple(b.major(), b.minor(), b.patch());
    }
    bool operator!=(const version& a, const version& b) {
        return !(a == b);
    }

    bool operator<(const version& a, const version& b) {
        return std::make_tuple(a.major(), a.minor(), a.patch()) < std::make_tuple(b.major(), b.minor(), b.patch());
    }
    bool operator>(const version& a, const version& b) {
        return b < a;
    }
    bool operator<=(const version& a, const version& b) {
        return !(a > b);
    }
    bool operator>=(const version& a, const version& b) {
        return !(a < b);
    }
}
