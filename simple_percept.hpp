#ifndef SIMPLE_PERCEPT_HPP
#define SIMPLE_PERCEPT_HPP

#include <vector>
#include <cassert>

template <typename T>
class SimplePercept
{
public:
    SimplePercept(unsigned int num, T mu) : mu_(mu)
    {
        weight_.resize(num);
    }
    T feedforward(const std::vector<T>& input) const
    {
        assert(input.size() == weight_.size());

        T result = T();
        for (int i = 0; i < weight_.size(); i++)
        {
            result += input[i] * weight_[i];
        }
        return result > 0 ? T(1) : T(0);
    }
    void train(const std::vector<T>& input, T y)
    {
        T output = feedforward(input);
        for (int i = 0; i < weight_.size(); i++)
        {
            weight_[i] = weight_[i] + (y - output) * input[i] * mu();
        }
    }
    const std::vector<T>& getWeight() const {return weight_;}
    T mu(){ return mu_; }
private:
    std::vector<T> weight_;
    T mu_;
};

#endif