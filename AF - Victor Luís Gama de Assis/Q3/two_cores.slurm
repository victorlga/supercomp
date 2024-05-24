#!/bin/bash
#SBATCH --job-name=victor
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=2
#SBATCH --cpus-per-task=1
#SBATCH --partition=espec
#SBATCH --mem=100M

export OMP_NUM_THREADS=2

echo Resultado usando 2 cores
./main