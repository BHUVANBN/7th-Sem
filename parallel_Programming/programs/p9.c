// Program 9: Write an MPI program demonstrating MPI_Reduce and MPI_Allreduce (MPI_MAX, MPI_MIN, MPI_SUM, MPI_PROD)
#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv) {
    int rank, value, sum, max;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    value = rank + 1;

    MPI_Reduce(&value, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        printf("Sum using Reduce: %d\n", sum);
    }

    MPI_Allreduce(&value, &max, 1, MPI_INT, MPI_MAX, MPI_COMM_WORLD);

    printf("Max using Allreduce (rank %d): %d\n", rank, max);
    MPI_Finalize();
    return 0;
}
/*
                                                                                      
┌──(kali㉿batman)-[~/7thSem/parallel_Programming/programs]
└─$ mpicc p9.c -o p9 
                                                                                      
┌──(kali㉿batman)-[~/7thSem/parallel_Programming/programs]
└─$ mpirun -np 4 ./p9

[batman][[36603,1],0][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[36603,1],2][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[36603,1],2][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[36603,1],0][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[36603,1],0][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[36603,1],2][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[36603,1],3][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[36603,1],1][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[36603,1],3][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[36603,1],1][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[36603,1],3][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[36603,1],1][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
Sum using Reduce: 10
Max using Allreduce (rank 0): 4
Max using Allreduce (rank 2): 4
Max using Allreduce (rank 1): 4
Max using Allreduce (rank 3): 4
*/