pipeline {
    agent any
    stages {
        stage('Checkout') {
            steps {
                // Clone main branch
                git url: 'https://github.com/bhoomikashirol/Demo-Project-for-Jenkins.git', branch: 'main'
                
                // Clone code branch and copy Code.cpp
                sh '''
                    git clone -b code https://github.com/bhoomikashirol/Demo-Project-for-Jenkins.git code-branch
                    cp code-branch/Code.cpp .
                    rm -rf code-branch
                '''
                
                // Clone Test branch and copy CodeTest.cpp
                sh '''
                    git clone -b Test https://github.com/bhoomikashirol/Demo-Project-for-Jenkins.git test-branch
                    cp test-branch/CodeTest.cpp .
                    rm -rf test-branch
                '''
            }
        }
        stage('Build') {
            steps {
                sh '''
                    mkdir -p build
                    cd build
                    cmake ..
                    make
                '''
            }
        }
        stage('Test') {
            steps {
                sh '''
                    cd build
                    ./DemoTest
                '''
            }
        }
    }
}
