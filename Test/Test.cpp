#include <gtest/gtest.h>
#include <benchmark/benchmark.h>
#include <vector>
#include <memory>
#include <AlignedVector.h>

// Вспомогательная функция для заполнения векторов тестовыми данными
template <typename Vec>
void FillVector(Vec& vec, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        vec.push_back(static_cast<typename Vec::value_type>(i));
    }
}

// Тесты для целых чисел (int)
static void BM_AVectorIntAddition(benchmark::State& state)
{
    AVector<int> vec1(0);
    AVector<int> vec2(0);
    AVector<int> result(0);

    // Подготовка данных
    for (int i = 0; i < state.range(0); ++i)
    {
        vec1.Add(i);
        vec2.Add(i);
    }
    result.Reserve(state.range(0));

    for (auto _ : state)
    {
        for (size_t i = 0; i < vec1.GetSize(); ++i)
        {
            result[i] = vec1[i] + vec2[i];
        }
        benchmark::DoNotOptimize(result);
    }
}

static void BM_StdVectorIntAddition(benchmark::State& state)
{
    std::vector<int> vec1;
    std::vector<int> vec2;
    std::vector<int> result;

    // Подготовка данных
    vec1.reserve(state.range(0));
    vec2.reserve(state.range(0));
    result.reserve(state.range(0));

    for (int i = 0; i < state.range(0); ++i)
    {
        vec1.push_back(i);
        vec2.push_back(i);
        result.push_back(0);
    }

    for (auto _ : state)
    {
        for (size_t i = 0; i < vec1.size(); ++i)
        {
            result[i] = vec1[i] + vec2[i];
        }
        benchmark::DoNotOptimize(result);
    }
}

// Тесты для чисел с плавающей точкой (double)
static void BM_AVectorDoubleAddition(benchmark::State& state)
{
    AVector<double> vec1(0);
    AVector<double> vec2(0);
    AVector<double> result(0);

    for (int i = 0; i < state.range(0); ++i)
    {
        vec1.Add(static_cast<double>(i) * 1.1);
        vec2.Add(static_cast<double>(i) * 2.2);
    }
    result.Reserve(state.range(0));

    for (auto _ : state)
    {
        for (size_t i = 0; i < vec1.GetSize(); ++i)
        {
            result[i] = vec1[i] + vec2[i];
        }
        benchmark::DoNotOptimize(result);
    }
}

static void BM_StdVectorDoubleAddition(benchmark::State& state)
{
    std::vector<double> vec1;
    std::vector<double> vec2;
    std::vector<double> result;

    vec1.reserve(state.range(0));
    vec2.reserve(state.range(0));
    result.reserve(state.range(0));

    for (int i = 0; i < state.range(0); ++i)
    {
        vec1.push_back(static_cast<double>(i) * 1.1);
        vec2.push_back(static_cast<double>(i) * 2.2);
        result.push_back(0.0);
    }

    for (auto _ : state)
    {
        for (size_t i = 0; i < vec1.size(); ++i)
        {
            result[i] = vec1[i] + vec2[i];
        }
        benchmark::DoNotOptimize(result);
    }
}

// Тесты вычитания для целых чисел
static void BM_AVectorIntSubtraction(benchmark::State& state)
{
    AVector<int> vec1(0);
    AVector<int> vec2(0);
    AVector<int> result(0);

    for (int i = 0; i < state.range(0); ++i)
    {
        vec1.Add(i * 2);
        vec2.Add(i);
    }
    result.Reserve(state.range(0));

    for (auto _ : state)
    {
        for (size_t i = 0; i < vec1.GetSize(); ++i)
        {
            result[i] = vec1[i] - vec2[i];
        }
        benchmark::DoNotOptimize(result);
    }
}

static void BM_StdVectorIntSubtraction(benchmark::State& state)
{
    std::vector<int> vec1;
    std::vector<int> vec2;
    std::vector<int> result;

    vec1.reserve(state.range(0));
    vec2.reserve(state.range(0));
    result.reserve(state.range(0));

    for (int i = 0; i < state.range(0); ++i)
    {
        vec1.push_back(i * 2);
        vec2.push_back(i);
        result.push_back(0);
    }

    for (auto _ : state)
    {
        for (size_t i = 0; i < vec1.size(); ++i)
        {
            result[i] = vec1[i] - vec2[i];
        }
        benchmark::DoNotOptimize(result);
    }
}

// Тесты вычитания для чисел с плавающей точкой
static void BM_AVectorDoubleSubtraction(benchmark::State& state)
{
    AVector<double> vec1(0);
    AVector<double> vec2(0);
    AVector<double> result(0);

    for (int i = 0; i < state.range(0); ++i)
    {
        vec1.Add(static_cast<double>(i) * 3.3);
        vec2.Add(static_cast<double>(i) * 1.1);
    }
    result.Reserve(state.range(0));

    for (auto _ : state)
    {
        for (size_t i = 0; i < vec1.GetSize(); ++i)
        {
            result[i] = vec1[i] - vec2[i];
        }
        benchmark::DoNotOptimize(result);
    }
}

static void BM_StdVectorDoubleSubtraction(benchmark::State& state)
{
    std::vector<double> vec1;
    std::vector<double> vec2;
    std::vector<double> result;

    vec1.reserve(state.range(0));
    vec2.reserve(state.range(0));
    result.reserve(state.range(0));

    for (int i = 0; i < state.range(0); ++i)
    {
        vec1.push_back(static_cast<double>(i) * 3.3);
        vec2.push_back(static_cast<double>(i) * 1.1);
        result.push_back(0.0);
    }

    for (auto _ : state)
    {
        for (size_t i = 0; i < vec1.size(); ++i)
        {
            result[i] = vec1[i] - vec2[i];
        }
        benchmark::DoNotOptimize(result);
    }
}

// Регистрация бенчмарков с разными размерами
// Используем степени двойки для лучшей демонстрации эффекта выравнивания
BENCHMARK(BM_AVectorIntAddition)->Range(8, 8 << 13);
BENCHMARK(BM_StdVectorIntAddition)->Range(8, 8 << 13);
BENCHMARK(BM_AVectorDoubleAddition)->Range(8, 8 << 13);
BENCHMARK(BM_StdVectorDoubleAddition)->Range(8, 8 << 13);
BENCHMARK(BM_AVectorIntSubtraction)->Range(8, 8 << 13);
BENCHMARK(BM_StdVectorIntSubtraction)->Range(8, 8 << 13);
BENCHMARK(BM_AVectorDoubleSubtraction)->Range(8, 8 << 13);
BENCHMARK(BM_StdVectorDoubleSubtraction)->Range(8, 8 << 13);

// Настройки для более точных измерений
BENCHMARK_MAIN();