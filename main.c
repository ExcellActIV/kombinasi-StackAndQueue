#include <stdio.h>
#include "linked.h"
#include "stack.h"
#include "queue.h"

int main()
{
    address daftarTugas = Nil, newNode = Nil;
    Stack lacakTugas;   // Untuk menampung riwayat tugas yang telah dikerjakan, dengan tugas yang paling baru dikerjakan berada di atas
    Queue antrianTugas; // Untuk menampung tugas yang siap dikerjakan, dengan tugas terlama berada di depan
    int pilihan;        // Untuk menyimpan pilihan menu yang diinput user
    int tugas;          // Untuk menyimpan ID tugas yang diinput user

    createStack(&lacakTugas);
    createQueue(&antrianTugas);

    do
    {
        printf("\n=== Daftar Tugas ===\n");
        printf("1. Tampilkan Daftar Tugas\n");                // SLL
        printf("2. Tambah Tugas ke Daftar\n");                // SLL
        printf("3. Hapus Tugas dari Daftar\n");               // SLL
        printf("4. Masukkan Tugas ke Antrian\n");             // Queue
        printf("5. Tampilkan Antrian Tugas\n");               // Queue
        printf("6. Kerjakan Tugas\n");                        // Queue -> Stack
        printf("7. Tampilkan Tugas yang Sudah Dikerjakan\n"); // Stack
        printf("8. Keluar\n");
        printf("\nPilihan: ");

        scanf("%d", &pilihan);
        printf("\n");

        switch (pilihan)
        {
        case 1: // Tampilkan Daftar Tugas
            Tampil_List(daftarTugas);
            break;

        case 2: // Tambah Tugas ke Daftar
            printf("Masukkan ID tugas baru: ");
            scanf("%d", &tugas);
            Create_Node(&newNode, tugas);
            if (newNode != Nil) // Jika alokasi berhasil
            {
                Ins_Akhir(&daftarTugas, newNode);
            }
            else
            {
                printf("Gagal membuat node baru!\n");
            }
            break;

        case 3: // Hapus Tugas dari Daftar
            printf("Masukkan ID tugas yang ingin dihapus: ");
            scanf("%d", &tugas);
            Del_Awal(&daftarTugas, &tugas);
            break;

        case 4: // Masukkan Tugas ke Antrian yang akan dikerjakan
            printf("Masukkan ID tugas ke antrian: ");
            scanf("%d", &tugas);

            if (Search(daftarTugas, tugas) != Nil)
            {
                Create_Node(&newNode, tugas);
                enqueue(&antrianTugas, newNode);
                printf("Tugas %d berhasil dimasukkan ke antrian\n", tugas);
            }
            else
            {
                printf("Error: Tugas dengan ID %d tidak ada dalam daftar tugas!\n", tugas);
            }
            break;

        case 5: // Tampilkan Antrian Tugas
            printQueue(antrianTugas);
            break;

        case 6: // Kerjakan Tugas
            dequeue(&antrianTugas, &tugas);
            Create_Node(&newNode, tugas);
            push(&lacakTugas, tugas);
            break;

        case 7: // Tampilkan Tugas yang Sudah Dikerjakan
            printStack(lacakTugas);
            break;

        case 8: // Keluar
            printf("Program selesai\n");
            break;

        default:
            printf("Pilihan tidak valid, silahkan coba lagi\n");
            break;
        }
    } while (pilihan != 8);

    DeAlokasi(&daftarTugas);
    deleteQueue(&antrianTugas);
    deleteStack(&lacakTugas);

    return 0;
}