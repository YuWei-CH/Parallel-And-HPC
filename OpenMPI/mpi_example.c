#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    const int MSG_LENGTH = 100;
    char message[MSG_LENGTH];

    if (world_rank == 0) {
        // process 0 sent message
        strcpy(message, "Hello from process 0");
        for (int i = 1; i < world_size; i++) {
            MPI_Send(message, MSG_LENGTH, MPI_CHAR, i, 0, MPI_COMM_WORLD);
        }
    } else {
        // other processes recieved
        MPI_Recv(message, MSG_LENGTH, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process %d received message: %s\n", world_rank, message);
    }

    MPI_Finalize();
    return 0;
}
