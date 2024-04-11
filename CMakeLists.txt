cmake_minimum_required(VERSION 3.27)
project(GraphPlotter)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# set the path to the Qt installation
set(CMAKE_PREFIX_PATH "C:/Qt/6.4.2/mingw_64/lib/cmake")
set(QCUSTOMPLOT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/QCustomPlot)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        PrintSupport
        REQUIRED)

include_directories(${QCUSTOMPLOT_PATH}/include)
link_directories(${QCUSTOMPLOT_PATH}/bin)

add_executable(GraphPlotter main.cpp
        widgets/MainWindow/mainwindow.cpp
        widgets/MainWindow/mainwindow.h
        widgets/MainWindow/mainwindow.ui
        widgets/PointInputTabWidget/pointinputtabwidget.h
        widgets/PointInputTabWidget/pointinputtabwidget.cpp
        widgets/PointInputTabWidget/pointinputtabwidget.ui
        widgets/CreatePointsTabDialog/createpointstabdialog.h
        widgets/CreatePointsTabDialog/createpointstabdialog.cpp
        widgets/CreatePointsTabDialog/createpointstabdialog.ui
)

target_link_libraries(GraphPlotter
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::PrintSupport
        QCustomPlot
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets PrintSupport)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            "${QCUSTOMPLOT_PATH}/bin/libQCustomPlot.dll"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
endif ()
