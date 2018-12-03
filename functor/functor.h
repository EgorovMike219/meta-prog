#pragma once
#include "argsPack.h"
#include "delegate.h"


template <class TCE>
struct CEWrapper {
private:
    TCE m_CallableEntity;
public:
    explicit CEWrapper(const TCE& ptr) : m_CallableEntity(ptr) {}
    template<typename... Params2>
    auto operator()(Params2... args) const -> decltype(m_CallableEntity(args...)) {
        return m_CallableEntity(args...);
    }
};


template<class TCallableEntity, typename...Params>
class Functor: ArgsPack<Params...> {
private:
    TCallableEntity m_CallableEntity;
public:
    typedef ArgsPack<Params...> _base;

    template<typename... _Params>
    Functor(const TCallableEntity& ptr,  _Params&&... params)
        : m_CallableEntity(ptr)
        , _base(std::forward<_Params>(params)...)
    {}

    template<class TCE = TCallableEntity>
    auto Call() -> decltype(this->_base::Call(CEWrapper<TCE>(m_CallableEntity))) const {
        return _base::Call(m_CallableEntity);
    }
    template<class Object>
    auto Call(Object& object)
    -> decltype(this->_base::Call(SimpleDelegate<Object, TCallableEntity>(object,
                                                                           m_CallableEntity))) const {
        return _base::Call(SimpleDelegate<Object, TCallableEntity>(object, m_CallableEntity));
    }
};


template<class TCallableEntity, class...Params>
Functor<TCallableEntity, Params...> make_functor(const TCallableEntity& callable_entity,
                                                 Params&&... given_params) {
    return Functor<TCallableEntity, Params...>(callable_entity, std::forward<Params>(given_params)...);
}