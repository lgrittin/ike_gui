#include <OpenXLSX.hpp>
#include <cmath>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime> 
#include <string>
#include <vector>
#include <sstream>

using namespace std;
using namespace OpenXLSX;

struct DB_VERSION_BIT {
    uint16_t DB_VER_H : 4;
    uint16_t DB_VER_L1 : 6;
    uint16_t DB_VER_L2 : 6;
};

typedef union DB_VERSION {
    uint16_t all;
    struct DB_VERSION_BIT bit;
} DB_VERSION;

int main()
{
    cout << "******************\n";
    cout << "DB GENERATION\n";
    cout << "******************\n\n";

    XLDocument in_file_params_process;
    ofstream out_file_params_data_csv;
    ofstream out_file_process_data_csv;
    ofstream out_file_param_process_data_h;
    ofstream out_file_param_process_data_c;
    std::vector<std::string> row_str;

    in_file_params_process.open("./ike_params_process_data.xlsx");

    auto wks_version = in_file_params_process.workbook().worksheet("version");
    std::string version_str = wks_version.cell("A1").value();
    std::stringstream version_sstr(version_str);
    std::string db_version_H;
    std::getline(version_sstr, db_version_H, '.');
    std::string db_version_L1;
    std::getline(version_sstr, db_version_L1, '.');
    std::string db_version_L2;
    std::getline(version_sstr, db_version_L2, '.');

    // ************************** //
    // Generate params_data.csv
    //*************************** //

    std::cout << "******************\n";
    std::cout << "param_data.csv\n";
    std::cout << "******************\n\n";

    std::cout << "Opening params_data.csv...\n";
    out_file_params_data_csv.open("params_data.csv");

    std::cout << "Writing on params_data.csv...\n";
    out_file_params_data_csv << "#" << version_str << "\n";
    auto wks_params_data = in_file_params_process.workbook().worksheet("params_data");
    std::vector<std::vector<std::string>> params_data;
    for (auto& row : wks_params_data.rows())
    {
        row_str.clear();
        unsigned int i = 0;
        for (auto& value : std::vector<XLCellValue>(row.values()))
        {
            std::string value_str;
            if (value.type() == XLValueType::Integer)
            {
                int64_t value_int = value.get<std::int64_t>();
                value_str = std::to_string(value_int);
            }
            else if (value.type() == XLValueType::Float)
            {
                double value_double = value.get<double>();
                value_str = std::to_string(value_double);
            }
            else if (value.type() == XLValueType::String)
            {
                value_str = value.get<std::string>();
            }

            if (i == 0)
                out_file_params_data_csv << value;
            else
                out_file_params_data_csv << "," << value;
            row_str.push_back(value_str);
            i++;
        }
        out_file_params_data_csv << endl;
        params_data.push_back(row_str);
    }
    std::cout << "Finished writing file params_data.csv!\n\n";

    //*************************** //
    // Generate process_data.csv
    //*************************** //

    std::cout << "******************\n";
    std::cout << "process_data.csv\n";
    std::cout << "******************\n\n";

    std::cout << "Opening process_data.csv...\n";
    out_file_process_data_csv.open("process_data.csv");
    
    std::cout << "Writing on process_data.csv...\n";
    out_file_process_data_csv << "#" << version_str << "\n";
    auto wks_process_data = in_file_params_process.workbook().worksheet("process_data");
    std::vector<std::vector<std::string>> process_data;
    for (auto& row : wks_process_data.rows())
    {
        row_str.clear();
        unsigned int i = 0;
        for (auto& value : std::vector<XLCellValue>(row.values()))
        {
            std::string value_str;
            if (value.type() == XLValueType::Integer)
            {
                int64_t value_int = value.get<std::int64_t>();
                value_str = std::to_string(value_int);
            }
            else if (value.type() == XLValueType::Float)
            {
                double value_double = value.get<double>();
                value_str = std::to_string(value_double);
            }
            else if (value.type() == XLValueType::String)
            {
                value_str = value.get<std::string>();
            }

            if (i == 0)
                out_file_process_data_csv << value;
            else
                out_file_process_data_csv << "," << value;
            row_str.push_back(value_str);
            i++;
        }
        out_file_process_data_csv << endl;
        process_data.push_back(row_str);
    }
    std::cout << "Finished writing file process_data.csv!\n\n";

    //*************************** //
    // Generate param_process_data.h
    //*************************** //

    std::cout << "******************\n";
    std::cout << "param_process_data.h\n";
    std::cout << "******************\n\n";
    
    std::cout << "Opening param_process_data.h...\n";
    out_file_param_process_data_h.open("param_process_data.h");

    // Params
    unsigned int num_params = params_data.size() -1;
    unsigned int col_params_id_address = std::distance(params_data.at(0).begin(), std::find(params_data.at(0).begin(), params_data.at(0).end(), "id_address"));
    unsigned int col_params_dsp_family = std::distance(params_data.at(0).begin(), std::find(params_data.at(0).begin(), params_data.at(0).end(), "dsp_family"));
    unsigned int col_params_type = std::distance(params_data.at(0).begin(), std::find(params_data.at(0).begin(), params_data.at(0).end(), "type"));
    unsigned int col_params_val_actual = std::distance(params_data.at(0).begin(), std::find(params_data.at(0).begin(), params_data.at(0).end(), "val_actual"));
    unsigned int col_params_val_default = std::distance(params_data.at(0).begin(), std::find(params_data.at(0).begin(), params_data.at(0).end(), "val_default"));
    unsigned int col_params_val_min = std::distance(params_data.at(0).begin(), std::find(params_data.at(0).begin(), params_data.at(0).end(), "val_min"));
    unsigned int col_params_val_max = std::distance(params_data.at(0).begin(), std::find(params_data.at(0).begin(), params_data.at(0).end(), "val_max"));
    unsigned int col_params_unit = std::distance(params_data.at(0).begin(), std::find(params_data.at(0).begin(), params_data.at(0).end(), "unit"));
    unsigned int col_params_description = std::distance(params_data.at(0).begin(), std::find(params_data.at(0).begin(), params_data.at(0).end(), "description"));
    unsigned int col_params_dsp_name = std::distance(params_data.at(0).begin(), std::find(params_data.at(0).begin(), params_data.at(0).end(), "dsp_name"));
    unsigned int col_params_k_double_to_u16 = std::distance(params_data.at(0).begin(), std::find(params_data.at(0).begin(), params_data.at(0).end(), "k_double_to_u16"));
    unsigned int col_params_k_u16_to_double = std::distance(params_data.at(0).begin(), std::find(params_data.at(0).begin(), params_data.at(0).end(), "k_u16_to_double"));
    std::vector<std::string> params_families;
    for (unsigned int row = 1; row < params_data.size(); row++)
    {
        std::string family = params_data.at(row).at(col_params_dsp_family);
        if (std::find(params_families.begin(), params_families.end(), family) == params_families.end())
            params_families.push_back(family);
    }

    // Process
    unsigned int num_process = process_data.size() -1;
    unsigned int col_process_id_address = std::distance(process_data.at(0).begin(), std::find(process_data.at(0).begin(), process_data.at(0).end(), "id_address"));
    unsigned int col_process_dsp_family = std::distance(process_data.at(0).begin(), std::find(process_data.at(0).begin(), process_data.at(0).end(), "dsp_family"));
    unsigned int col_process_type = std::distance(process_data.at(0).begin(), std::find(process_data.at(0).begin(), process_data.at(0).end(), "type"));
    unsigned int col_process_val_actual = std::distance(process_data.at(0).begin(), std::find(process_data.at(0).begin(), process_data.at(0).end(), "val_actual"));
    unsigned int col_process_val_min = std::distance(process_data.at(0).begin(), std::find(process_data.at(0).begin(), process_data.at(0).end(), "val_min"));
    unsigned int col_process_val_max = std::distance(process_data.at(0).begin(), std::find(process_data.at(0).begin(), process_data.at(0).end(), "val_max"));
    unsigned int col_process_unit = std::distance(process_data.at(0).begin(), std::find(process_data.at(0).begin(), process_data.at(0).end(), "unit"));
    unsigned int col_process_description = std::distance(process_data.at(0).begin(), std::find(process_data.at(0).begin(), process_data.at(0).end(), "description"));
    unsigned int col_process_dsp_name = std::distance(process_data.at(0).begin(), std::find(process_data.at(0).begin(), process_data.at(0).end(), "dsp_name"));
    unsigned int col_process_k_double_to_u16 = std::distance(process_data.at(0).begin(), std::find(process_data.at(0).begin(), process_data.at(0).end(), "k_double_to_u16"));
    unsigned int col_process_k_u16_to_double = std::distance(process_data.at(0).begin(), std::find(process_data.at(0).begin(), process_data.at(0).end(), "k_u16_to_double"));
    std::vector<std::string> process_families;
    for (unsigned int row = 1; row < process_data.size(); row++)
    {
        std::string family = process_data.at(row).at(col_process_dsp_family);
        if (std::find(process_families.begin(), process_families.end(), family) == process_families.end())
            process_families.push_back(family);
    }

    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    std::string date = std::to_string(now->tm_year + 1900) + " " + std::to_string(now->tm_mon + 1) + " " + std::to_string(now->tm_mday);

    std::cout << "Writing on param_process_data.h...\n";
    out_file_param_process_data_h <<
        "//########################################################################\n" <<
        "//  Project     :   launch_f280039c_template                              \n" <<
        "//  Target      :                                                         \n" <<
        "//------------------------------------------------------------------------\n" <<
        "//  Filename    :   param_process_data.h                                  \n" <<
        "//  Author      :   lucag                                                 \n" <<
        "//  Date        :   " << date << "                                        \n" <<
        "//------------------------------------------------------------------------\n" <<
        "//  History     :                                                         \n" <<
        "//  23 Aug 2023     - Creation                                            \n" <<
        "//                                                                        \n" <<
        "//------------------------------------------------------------------------\n" <<
        "//!  Description:    " << version_str << "                                    \n" <<
        "//!                                                                       \n" <<
        "//                                                                        \n" <<
        "//########################################################################\n" <<
        "                                                                          \n" <<
        "#ifndef INC_PARAM_PROCESS_DATA_H_                                         \n" <<
        "#define INC_PARAM_PROCESS_DATA_H_                                         \n" <<
        "                                                                          \n" <<
        "                                                                          \n" <<
        "/* ## COMMON Section ################################################## */\n" <<
        "/* ## These defines are visibles in all files                           */\n" <<
        "/* #################################################################### */\n" <<
        "                                                                          \n" <<
        "/* ## COMMON Includes ################################################# */\n" <<
        "                                                                          \n" <<
        "/* ## COMMON Defines ################################################## */\n" <<
        "                                                                          \n" <<
        "#define PARAMS_LENGTH " << std::to_string(num_params) << "\n" <<
        "#define PROCESS_LENGTH " << std::to_string(num_process) << "\n" <<
        "#define PARAMS_FIRST_ADDRESS " << params_data.at(1).at(col_params_id_address) << "\n" <<
        "#define PARAMS_LAST_ADDRESS PARAMS_FIRST_ADDRESS + PARAMS_LENGTH - 1\n" <<
        "#define PROCESS_FIRST_ADDRESS PARAMS_LAST_ADDRESS + 1\n" <<
        "#define PROCESS_LAST_ADDRESS PROCESS_FIRST_ADDRESS + PROCESS_LENGTH - 1\n" <<
        "#define DB_VERSION_H " << db_version_H << "\n"
        "#define DB_VERSION_L1 " << db_version_L1 << "\n"
        "#define DB_VERSION_L2 " << db_version_L2 << "\n"
        "                                                                          \n" <<
        "typedef enum {                                                            \n" <<
        "    word = 0,                                                             \n" <<
        "    uint = 1,                                                             \n" <<
        "    real = 2,                                                             \n" <<
        "    integer = 3                                                           \n" <<
        "} TYPE;                                                                   \n" <<
        "                                                                          \n" <<
        "typedef enum {                                                            \n";
    for (unsigned int i = 0; i < params_families.size(); i++)
    {
        out_file_param_process_data_h << "    " << params_families.at(i) << " = " << i;
        if (i < (params_families.size() - 1))
            out_file_param_process_data_h << ",\n";
        else
            out_file_param_process_data_h << "\n";
    }
    out_file_param_process_data_h <<
        "} PARAMS_FAMILY;                                                          \n" <<
        "                                                                          \n" <<
        "typedef enum {                                                            \n";
    for (unsigned int i = 0; i < process_families.size(); i++)
    {
        out_file_param_process_data_h << "    " << process_families.at(i) << " = " << i;
        if (i < (process_families.size() - 1))
            out_file_param_process_data_h << ",\n";
        else
            out_file_param_process_data_h << "\n";
    }
    out_file_param_process_data_h <<
        "} PROCESS_FAMILY;                                                         \n" <<
        "                                                                          \n" <<
        "struct DATA {                                                             \n" <<
        "    unsigned int id_address;                                              \n" <<
        "    unsigned int group;                                                   \n" <<
        "    TYPE type;                                                            \n" <<
        "    unsigned int* val_modbus;                                             \n" <<
        "    float k_double_to_u16;                                                \n" <<
        "    float k_u16_to_double;                                                \n" <<
        "    void* val;                                                            \n" <<
        "    float lim_min;                                                        \n" <<
        "    float lim_max;                                                        \n" <<
        "};                                                                        \n" <<
        "                                                                          \n" <<
        "                                                                          \n" <<
        "/* ## EXTERNAL Section ################################################ */\n" <<
        "/* ## These Vars/Prototypes are visibles in all files                   */\n" <<
        "/* #################################################################### */\n" <<
        "                                                                          \n" <<
        "/* ## EXTERNAL Prototypes ############################################# */\n" <<
        "                                                                          \n" <<
        "extern void updateSingleParamDataIn(unsigned int idx);                    \n" <<
        "extern void updateSingleProcessDataOut(unsigned int idx);                 \n" <<
        "extern void updateParamsDataIn();                                         \n" <<
        "extern void updateParamsProcessDataOut();                                 \n" <<
        "                                                                          \n" <<
        "/* ## EXTERNAL Vars ################################################### */\n" <<
        "                                                                          \n" <<
        "extern struct DATA process_data[PROCESS_LENGTH];                          \n" <<
        "extern struct DATA params_data[PARAMS_LENGTH];                            \n" <<
        "                                                                          \n" <<
        "                                                                          \n" <<
        "#endif /* INC_PARAM_PROCESS_DATA_H_ */                                    \n" <<
        "                                                                          \n" <<
        "/* #################################################################### */\n" <<
        "/* #################################################################### */\n";
    
    std::cout << "Finished writing file param_process_data.h!\n\n";

    //*************************** //
    // Generate param_process_data.c
    //*************************** //

    std::cout << "******************\n";
    std::cout << "param_process_data.c\n";
    std::cout << "******************\n\n";
    
    std::cout << "Opening param_process_data.c...\n";
    out_file_param_process_data_c.open("param_process_data.c");
    
    std::cout << "Writing on param_process_data.c...\n";
    out_file_param_process_data_c <<
        "//########################################################################\n" <<
        "//  Project     :   launch_f280039c_template                              \n" <<
        "//  Target      :                                                         \n" <<
        "//------------------------------------------------------------------------\n" <<
        "//  Filename    :   param_process_data.c                                  \n" <<
        "//  Author      :   lucag                                                 \n" <<
        "//  Date        :   " << date << "                                        \n" <<
        "//------------------------------------------------------------------------\n" <<
        "//  History     :                                                         \n" <<
        "//  23 Aug 2023     - Creation                                            \n" <<
        "//                                                                        \n" <<
        "//------------------------------------------------------------------------\n" <<
        "//!  Description:    " << version_str << "                                    \n" <<
        "//!                                                                       \n" <<
        "//                                                                        \n" <<
        "//########################################################################\n" <<
        "                                                                          \n" <<
        "/* ## Defines ######################################################### */\n" <<
        "                                                                          \n" <<
        "/* ## Header Includes ################################################# */\n" <<
        "                                                                          \n" <<
        "#include \"param_process_data.h\"                                         \n" <<
        "#include \"globals.h\"                                                    \n" <<
        "#if MB_LIBMODBUS_TESTS == false                                           \n" <<
        "#include \"modbus_rtu/ModbusDataMap.h\"                                   \n" <<
        "#else                                                                     \n" <<
        "#include \"modbus_rtu/ModbusDataMapTests.h\"                              \n" <<
        "#endif                                                                    \n" <<
        "                                                                          \n" <<
        "/* ## Local Vars ###################################################### */\n" <<
        "                                                                          \n" <<
        "struct DATA params_data[] =                                               \n" <<
        "{                                                                         \n";
    for (unsigned int row = 1; row < params_data.size(); row++)
    {
        out_file_param_process_data_c << "    " << "//" << params_data.at(row).at(col_params_description) << ",\n";
        out_file_param_process_data_c << "    " << params_data.at(row).at(col_params_id_address) << ",\n";
        out_file_param_process_data_c << "    " << params_data.at(row).at(col_params_dsp_family) << ",\n";
        out_file_param_process_data_c << "    " << params_data.at(row).at(col_params_type) << ",\n";
        out_file_param_process_data_c << "    " << "&mb.holdingRegisters.dummy" << std::to_string(row - 1) << ",\n";
        out_file_param_process_data_c << "    " << params_data.at(row).at(col_params_k_double_to_u16) << ",\n";
        out_file_param_process_data_c << "    " << params_data.at(row).at(col_params_k_u16_to_double) << ",\n";
        out_file_param_process_data_c << "    " << "&" << params_data.at(row).at(col_params_dsp_name) << ",\n";
        out_file_param_process_data_c << "    " << params_data.at(row).at(col_params_val_min) << ",\n";
        out_file_param_process_data_c << "    " << params_data.at(row).at(col_params_val_max);
        if (row < params_data.size() - 1)
            out_file_param_process_data_c << ",\n\n";
        else
            out_file_param_process_data_c << "\n";
    }
    out_file_param_process_data_c <<
        "};                                                                        \n" <<
        "                                                                          \n" <<
        "struct DATA process_data[] =                                              \n" <<
        "{                                                                         \n";
    for (unsigned int row = 1; row < process_data.size(); row++)
    {
        out_file_param_process_data_c << "    " << "//" << process_data.at(row).at(col_process_description) << ",\n";
        out_file_param_process_data_c << "    " << process_data.at(row).at(col_process_id_address) << ",\n";
        out_file_param_process_data_c << "    " << process_data.at(row).at(col_process_dsp_family) << ",\n";
        out_file_param_process_data_c << "    " << process_data.at(row).at(col_process_type) << ",\n";
        out_file_param_process_data_c << "    " << "&mb.holdingRegisters.dummy" << std::to_string(params_data.size() + row - 2) << ",\n";
        out_file_param_process_data_c << "    " << process_data.at(row).at(col_process_k_double_to_u16) << ",\n";
        out_file_param_process_data_c << "    " << process_data.at(row).at(col_process_k_u16_to_double) << ",\n";
        out_file_param_process_data_c << "    " << "&" << process_data.at(row).at(col_process_dsp_name) << ",\n";
        out_file_param_process_data_c << "    " << process_data.at(row).at(col_process_val_min) << ",\n";
        out_file_param_process_data_c << "    " << process_data.at(row).at(col_process_val_max);
        if (row < process_data.size() - 1)
            out_file_param_process_data_c << ",\n\n";
        else
            out_file_param_process_data_c << "\n";
    }    out_file_param_process_data_c <<
        "};                                                                        \n" <<
        "                                                                          \n" <<
        "/* #################################################################### */\n" <<
        "/* ############################# CODE ################################# */\n" <<
        "                                                                          \n" <<
        "void updateSingleParamDataIn(unsigned int modbus_address)                 \n" <<
        "{                                                                         \n" <<
        "    if ((modbus_address >= PARAMS_FIRST_ADDRESS) && (modbus_address <= PARAMS_LAST_ADDRESS))  \n" <<
        "    {                                                                     \n" <<
        "        Uint16 idx = modbus_address - PARAMS_FIRST_ADDRESS;               \n" <<
        "        switch (params_data[idx].type)                                    \n" <<
        "        {                                                                 \n" <<
        "        case integer:                                                     \n" <<
        "            *(int*)params_data[idx].val =                                 \n" <<
        "                ((*params_data[idx].val_modbus *                          \n" <<
        "                params_data[idx].k_u16_to_double) +                       \n" <<
        "                __f32toui16r(params_data[idx].lim_min));                  \n" <<
        "            break;                                                        \n" <<
        "        case word:                                                        \n" <<
        "        case uint:                                                        \n" <<
        "            *(unsigned int*)params_data[idx].val =                        \n" <<
        "                ((*params_data[idx].val_modbus *                          \n" <<
        "                params_data[idx].k_u16_to_double) +                       \n" <<
        "                __f32toui16r(params_data[idx].lim_min));                  \n" <<
        "            break;                                                        \n" <<
        "        case real:                                                        \n" <<
        "            *(float*)params_data[idx].val =                               \n" <<
        "                ((*params_data[idx].val_modbus *                          \n" <<
        "                params_data[idx].k_u16_to_double) +                       \n" <<
        "                params_data[idx].lim_min);                                \n" <<
        "            break;                                                        \n" <<
        "        }                                                                 \n" <<
        "    }                                                                     \n" <<
        "}                                                                         \n" <<
        "                                                                          \n" <<
        "void updateSingleProcessDataOut(unsigned int modbus_address)              \n" <<
        "{                                                                         \n" <<
        "    if ((modbus_address >= PROCESS_FIRST_ADDRESS) && (modbus_address <= PROCESS_LAST_ADDRESS))  \n" <<
        "    {                                                                     \n" <<
        "        Uint16 idx = modbus_address - PROCESS_FIRST_ADDRESS;              \n" <<
        "        switch (process_data[idx].type)                                   \n" <<
        "        {                                                                 \n" <<
        "        case word:                                                        \n" <<
        "        case uint:                                                        \n" <<
        "            *process_data[idx].val_modbus =                               \n" <<
        "                (*(unsigned int*)process_data[idx].val -                  \n" <<
        "                __f32toui16r(process_data[idx].lim_min))*                 \n" <<
        "                process_data[idx].k_double_to_u16;                        \n" <<
        "            break;                                                        \n" <<
        "        case real:                                                        \n" <<
        "            *process_data[idx].val_modbus =                               \n" <<
        "                (*(float*)process_data[idx].val -                         \n" <<
        "                process_data[idx].lim_min)*                               \n" <<
        "                process_data[idx].k_double_to_u16;                        \n" <<
        "            break;                                                        \n" <<
        "        }                                                                 \n" <<
        "    }                                                                     \n" <<
        "}                                                                         \n" <<
        "                                                                          \n" <<
        "void updateParamsDataIn()                                                 \n" <<
        "{                                                                         \n" <<
        "    Uint16 i;                                                             \n" <<
        "    for (i = 0; i < PARAMS_LENGTH; i++)                                   \n" <<
        "    {                                                                     \n" <<
        "        switch (params_data[i].type)                                      \n" <<
        "        {                                                                 \n" <<
        "        case integer:                                                     \n" <<
        "            *(int*)params_data[i].val =                                   \n" <<
        "                ((*params_data[i].val_modbus *                            \n" <<
        "                params_data[i].k_u16_to_double) +                         \n" <<
        "                __f32toui16r(params_data[i].lim_min));                    \n" <<
        "            break;                                                        \n" <<
        "        case word:                                                        \n" <<
        "        case uint:                                                        \n" <<
        "            *(unsigned int*)params_data[i].val =                          \n" <<
        "                ((*params_data[i].val_modbus *                            \n" <<
        "                    params_data[i].k_u16_to_double) +                     \n" <<
        "                    __f32toui16r(params_data[i].lim_min));                \n" <<
        "            break;                                                        \n" <<
        "        case real:                                                        \n" <<
        "            *(float*)params_data[i].val =                                 \n" <<
        "                ((*params_data[i].val_modbus *                            \n" <<
        "                    params_data[i].k_u16_to_double) +                     \n" <<
        "                    params_data[i].lim_min);                              \n" <<
        "            break;                                                        \n" <<
        "        }                                                                 \n" <<
        "    }                                                                     \n" <<
        "}                                                                         \n" <<
        "                                                                          \n" <<
        "void updateParamsProcessDataOut()                                         \n" <<
        "{                                                                         \n" <<
        "    Uint16 i;                                                             \n" <<
        "                                                                          \n" <<
        "    for (i = 0; i < PROCESS_LENGTH; i++)                                  \n" <<
        "    {                                                                     \n" <<
        "        switch (process_data[i].type)                                     \n" <<
        "        {                                                                 \n" <<
        "        case word:                                                        \n" <<
        "        case uint:                                                        \n" <<
        "            *process_data[i].val_modbus =                                 \n" <<
        "                (*(unsigned int*)process_data[i].val -                    \n" <<
        "                    __f32toui16r(process_data[i].lim_min)) *              \n" <<
        "                process_data[i].k_double_to_u16;                          \n" <<
        "            break;                                                        \n" <<
        "        case real:                                                        \n" <<
        "            *process_data[i].val_modbus =                                 \n" <<
        "                (*(float*)process_data[i].val -                           \n" <<
        "                    process_data[i].lim_min) *                            \n" <<
        "                process_data[i].k_double_to_u16;                          \n" <<
        "            break;                                                        \n" <<
        "        }                                                                 \n" <<
        "    }                                                                     \n" <<
        "                                                                          \n" <<
        "    for (i = 0; i < PARAMS_LENGTH; i++)                                   \n" <<
        "    {                                                                     \n" <<
        "        switch (params_data[i].type)                                      \n" <<
        "        {                                                                 \n" <<
        "        case word:                                                        \n" <<
        "        case uint:                                                        \n" <<
        "            *params_data[i].val_modbus =                                  \n" <<
        "                (*(unsigned int*)params_data[i].val -                     \n" <<
        "                    __f32toui16r(params_data[i].lim_min)) *               \n" <<
        "                params_data[i].k_double_to_u16;                           \n" <<
        "            break;                                                        \n" <<
        "        case real:                                                        \n" <<
        "            *params_data[i].val_modbus =                                  \n" <<
        "                (*(float*)params_data[i].val -                            \n" <<
        "                    params_data[i].lim_min) *                             \n" <<
        "                params_data[i].k_double_to_u16;                           \n" <<
        "            break;                                                        \n" <<
        "        }                                                                 \n" <<
        "    }                                                                     \n" <<
        "}                                                                         \n" <<
        "                                                                          \n" <<
        "/* #################################################################### */\n" <<
        "/* #################################################################### */\n";
    
    std::cout << "Finished writing file param_process_data.c!\n\n";
    std::cout << "Closing all files...\n\n";
    out_file_param_process_data_h.close();
    out_file_param_process_data_c.close();
    in_file_params_process.close();
    out_file_params_data_csv.close();
    out_file_process_data_csv.close();
    std::cout << "All files closed!\n\n";

    return 0;
}