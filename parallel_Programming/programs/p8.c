//Program 8. Write a MPI Program demonstration of MPI_Scatter and MPI_Gather

#include <stdio.h>
#include <mpi.h>
int main(int argc, char** argv){
    int rank, size, send_data[4] = {10, 20, 30, 40}, recv_data;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Scatter(send_data, 1, MPI_INT, &recv_data, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("Process %d received: %d\n", rank, recv_data);
    
    recv_data += 1;
    MPI_Gather(&recv_data, 1, MPI_INT, send_data, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if (rank == 0){
        printf("Gathered data: ");
        for (int i = 0; i< size; i++)
            printf("%d ", send_data[i]);
        printf("\n");
    }
    MPI_Finalize();
    return 0;
}
/*                                                                                     
┌──(kali㉿batman)-[~/7thSem/parallel_Programming/programs]
└─$ mpicc p8.c -o p8 
                                                                                    
┌──(kali㉿batman)-[~/7thSem/parallel_Programming/programs]
└─$ mpirun -np 4 ./p8

[batman][[59737,1],2][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[59737,1],0][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[59737,1],2][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[59737,1],0][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[59737,1],2][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[59737,1],0][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[59737,1],1][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[59737,1],3][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[59737,1],1][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[59737,1],3][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[59737,1],1][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
[batman][[59737,1],3][../../../../../../opal/mca/btl/tcp/btl_tcp_proc.c:266:mca_btl_tcp_proc_create_interface_graph] Unable to find reachable pairing between local and remote interfaces
Process 0 received: 10
Gathered data: 11 21 31 41 
Process 2 received: 30
Process 1 received: 20
Process 3 received: 40
*/