#pragma once


template<class TObject, typename TCE>
struct SimpleDelegate {
private:
    TObject& m_Object;
    TCE m_CallableEntity;
public:
    SimpleDelegate(TObject& object, const TCE& ptr)
            : m_Object(object), m_CallableEntity(ptr)
    {}

    template<typename... Params2>
    auto operator()(Params2... args) const
        -> decltype((m_Object.*m_CallableEntity) (args...))
    {
        return (m_Object.*m_CallableEntity) (args...);
    }
};
