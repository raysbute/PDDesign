typedef struct Patient {
    char name[20];
    int age;
    char reg_id[20];   // 挂号号（唯一）
    struct MedicalRecord *records; // 该患者的诊疗记录链表
    struct Patient *next;
} Patient;

typedef struct Doctor {
    char name[20];
    char id[20];       // 工号（唯一）
    char level[20];    // 职级
    char dept[20];     // 科室
    char schedule[50]; // 出诊时间
    struct Doctor *next;
} Doctor;

typedef struct MedicalRecord {
    char reg_id[20];   // 挂号号（唯一标识一条记录）

    Patient *patient;
    Doctor *doctor;

    int type; // 1检查 2开药 3住院

    union {
        struct {
            float items[30];
            int count;
            float total;
        } check;

        struct {
            char name[30][20];
            float price[30];
            int num[30];
            int count;
            float total;
        } medicine;

        struct {
            int start_day, end_day;
            float deposit;
        } hospital;
    } detail;

    struct MedicalRecord *next;
} MedicalRecord;

typedef struct {
    Patient *patients;
    Doctor *doctors;
    MedicalRecord *records;

    float total_income;
} System;