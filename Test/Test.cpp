#include <gtest/gtest.h>
#include <benchmark/benchmark.h>
#include <vector>
#include <memory>
#include <AlignedVector.h>

// Тест вставки элементов
static void BM_AVectorPushBack(benchmark::State& state)
{
    for (auto _ : state)
    {
        AVector<int> vec(0);
        for (int i = 0; i < state.range(0); ++i)
        {
            vec.Add(i);
        }
    }
}

static void BM_StdVectorPushBack(benchmark::State& state)
{
    for (auto _ : state)
    {
        std::vector<int> vec;
        for (int i = 0; i < state.range(0); ++i)
        {
            vec.push_back(i);
        }
    }
}

// Тест доступа к элементам
static void BM_AVectorAccess(benchmark::State& state)
{
    AVector<int> vec(0);
    for (int i = 0; i < state.range(0); ++i)
    {
        vec.Add(i);
    }

    for (auto _ : state)
    {
        for (size_t i = 0; i < vec.GetSize(); ++i)
        {
            benchmark::DoNotOptimize(vec[i]);
        }
    }
}

static void BM_StdVectorAccess(benchmark::State& state)
{
    std::vector<int> vec;
    for (int i = 0; i < state.range(0); ++i)
    {
        vec.push_back(i);
    }

    for (auto _ : state)
    {
        for (size_t i = 0; i < vec.size(); ++i)
        {
            benchmark::DoNotOptimize(vec[i]);
        }
    }
}

// Регистрация бенчмарков с разными размерами
BENCHMARK(BM_AVectorPushBack)->Range(8, 8 << 10);
BENCHMARK(BM_StdVectorPushBack)->Range(8, 8 << 10);
BENCHMARK(BM_AVectorAccess)->Range(8, 8 << 10);
BENCHMARK(BM_StdVectorAccess)->Range(8, 8 << 10);

BENCHMARK_MAIN();