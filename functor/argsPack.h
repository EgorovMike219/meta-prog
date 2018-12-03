#pragma once


template<typename T>
T* ConvertToPtr(T& t) {
    return &t;
}
template<typename T>
T* ConvertToPtr(T* t) {
    return t;
}

template<typename T>
T& ConvertToRef(T& t) {
    return t;
}
template<typename T>
T& ConvertToRef(T* t) {
    return *t;
}

template<typename...Tail>
class ArgsPack;

template<>
class ArgsPack<> {
public:
    ArgsPack() {}

    template<class Delegate, typename... Args>
    auto Call(const Delegate& delegate, Args&&... args) -> decltype(delegate(args...))
    {
        return delegate(args...);
    }
};

template<typename Head, typename ...Tail>
class ArgsPack<Head, Tail...> : ArgsPack<Tail...> {
private:
    Head m_Param;
public:
    typedef ArgsPack<Tail...> __base;

    template<typename _Head, typename... _Tail>
    ArgsPack(_Head&& head, _Tail&&... tail)
            : __base(std::forward<_Tail>(tail)...),
              m_Param(std::forward<Head>(head))
    {
    }

    template<class Delegate, typename... Args>
    auto Call(const Delegate& delegate, Args&&... args)
    -> decltype(this->__base::Call(delegate, args..., ConvertToRef(m_Param))) {
        return __base::Call(delegate, args..., ConvertToRef(m_Param));
    }

    template<class Delegate, typename... Args>
    auto Call(const Delegate& delegate, Args&&... args)
    -> decltype(this->__base::Call(delegate, args..., ConvertToPtr(m_Param))) {
        return __base::Call(delegate, args..., ConvertToPtr(m_Param));
    }
};