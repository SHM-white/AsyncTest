#include "requests.h"
#include <iostream>
#include "hv.h"
#include "include.h"

#include <string>
#include <chrono>
#include <thread>
#include <future>
#include <fcntl.h>


auto getWeather(int code = 110101) {
    auto resp = requests::get(std::format("https://restapi.amap.com/v3/weather/weatherInfo?city={}&key=7654cff2801031c93fba40fe770e7016&extensions=all", code).c_str());
    return resp;
}

int main() {
    _setmode(_fileno(stdout), _O_U8TEXT);

    std::wcout << L"main start" << std::this_thread::get_id() << std::endl;

    //获取开始时间
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

    auto resultFromDB = std::async(std::launch::async, getWeather, 320612);

    std::future_status status;
    std::string dbData;
    do
    {
        status = resultFromDB.wait_for(std::chrono::microseconds(1));

        switch (status)
        {
        case std::future_status::ready:
            std::wcout << "Ready..." << std::endl;
            //获取结果
            dbData = resultFromDB.get().get()->body;
            std::wcout << u8tw(dbData) << std::endl;
            break;
        case std::future_status::timeout:
            std::wcout << "timeout..." << std::endl;
            break;
        case std::future_status::deferred:
            std::wcout << "deferred..." << std::endl;
            break;
        default:
            break;
        }

    } while (status != std::future_status::ready);


    //获取结束时间
    auto end = std::chrono::system_clock::now();

    auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::wcout << "Total Time taken= " << diff << "microseconds" << std::endl;

    return 0;
}