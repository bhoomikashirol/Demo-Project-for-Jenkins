pipeline {
    agent any

    stages {
        stage('---clean---') {
            steps {
                sh 'rm -rf build'
            }
        }

        stage('--checkout--') {
            steps {
                sh 'git clone -b main https://github.com/bhoomikashirol/Demo-Project-for-Jenkins.git'
                sh 'git clone -b code https://github.com/bhoomikashirol/Demo-Project-for-Jenkins.git code-branch'
                sh 'git clone -b Test https://github.com/bhoomikashirol/Demo-Project-for-Jenkins.git test-branch'
                sh 'cp code-branch/Code.cpp Demo-Project-for-Jenkins/'
                sh 'cp test-branch/CodeTest.cpp Demo-Project-for-Jenkins/'
            }
        }

        stage('--verify-files--') {
            steps {
                sh 'ls -la Demo-Project-for-Jenkins'
            }
        }

        stage('--build--') {
            steps {
                sh '''
                    mkdir -p build
                    cd build
                    cmake ..
                    make
                '''
            }
        }

        stage('--test--') {
            steps {
                sh '''
                    cd build
                    ./DemoTest
                '''
            }
        }

        stage('--package--') {
            steps {
                sh '''
                    cd build
                    make package
                '''
            }
        }
    }
}
